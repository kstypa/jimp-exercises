//
// Created by karol on 5/18/17.
//

#include "Scheduler.h"
#include "../algotest/Algo.h"
#include <algorithm>

using algo::Contains;

namespace academia {

//    SchedulingItem

    SchedulingItem::SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_)
            : course_id_(course_id_), teacher_id_(teacher_id_), room_id_(room_id_), time_slot_(time_slot_),
              year_(year_) {}

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }

//    Schedule

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule OfTeacher;
        for(auto n : items_) {
            if(n.TeacherId() == teacher_id)
                OfTeacher.InsertScheduleItem(n);
        }
        return OfTeacher;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule OfRoom;
        for(auto n : items_) {
            if(n.RoomId() == room_id)
                OfRoom.InsertScheduleItem(n);
        }
        return OfRoom;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule OfYear;
        for(auto n : items_) {
            if(n.Year() == year)
                OfYear.InsertScheduleItem(n);
        }
        return OfYear;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> UsedTimeSlots;
        for(auto n : items_)
            UsedTimeSlots.push_back(n.TimeSlot());
        std::vector<int> AvailableTimeSlots;
        for(int i = 1; i <= n_time_slots; ++i)
            if(!Contains(UsedTimeSlots, i))
                AvailableTimeSlots.push_back(i);
        return AvailableTimeSlots;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        items_.push_back(item);
    }

    size_t Schedule::Size() const {
        return items_.size();
    }

    SchedulingItem Schedule::operator[](int index) const {
        return items_[index];
    }

//    GreedyScheduler

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule NewSchedule;
        int year, teacher, time_slot = 0, needed_slots = 0;
        bool inserted, slot_found;

        if(NewSchedule.AvailableTimeSlots(n_time_slots).size() <= 0)
            throw NoViableSolutionFound();

        for(auto x : teacher_courses_assignment) {
            for(auto y : x.second)
                ++needed_slots;
        }

        if(needed_slots > (n_time_slots * rooms.size()))
            throw NoViableSolutionFound();

        for(auto t : teacher_courses_assignment) {
            teacher = t.first;

            if(NewSchedule.OfTeacher(teacher).AvailableTimeSlots(n_time_slots).size() <= 0)
                throw NoViableSolutionFound();

            for(auto course : t.second) {
                inserted = false;

                for(auto room : rooms) {

                        for(auto n : courses_of_year) {
                            year = n.first;
                            if(NewSchedule.OfYear(year).AvailableTimeSlots(n_time_slots).size() <= 0)
                                throw NoViableSolutionFound();

                            slot_found = false;
                            for(auto year_slot : NewSchedule.OfYear(year).AvailableTimeSlots(n_time_slots)) {
                                for(auto room_slot : NewSchedule.OfRoom(room).AvailableTimeSlots(n_time_slots)) {
                                    if(year_slot != room_slot)
                                        continue;
                                    for(auto teacher_slot : NewSchedule.OfTeacher(teacher).AvailableTimeSlots(n_time_slots)) {
                                        if(teacher_slot != room_slot)
                                            continue;
                                        if((year_slot == room_slot) && (year_slot == teacher_slot) && (room_slot == teacher_slot)) {
                                            time_slot = year_slot;
                                            slot_found = true;
                                            break;
                                        }
                                    }
                                    if(slot_found) break;
                                }
                                if(slot_found) break;
                            }

                            for(auto c : n.second) {
                                if(c == course  && slot_found) {
                                    NewSchedule.InsertScheduleItem(SchedulingItem{course, teacher, room, time_slot, year});
                                    inserted = true;
                                    break;
                                }
                            }
                            if(inserted) break;
                        }
                    if(inserted) break;
                }
            }
        }

        return NewSchedule;
    }

//    NoViableSolutionFound

    NoViableSolutionFound::NoViableSolutionFound() : runtime_error("No viable solution found") {}

}