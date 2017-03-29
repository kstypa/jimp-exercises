//
// Created by karol on 3/29/17.
//

#include "SimpleTemplateEngine.h"

using ::std::string;
using ::std::unordered_map;

namespace nets {
    View::View(string templ) {
        template_ = templ;
        int opencount = 0, closecount = 0, oldopencount = 0, oldclosecount = 0;
        size_t left = 0, right = 0;
        for(size_t i = 0; i < templ.size(); i++){
            if(templ[i] == '{') {
                opencount++;
                left = i;
                if(opencount > 2) {
                    oldopencount = opencount;
                    opencount = 2;
                }
            }
            else if(templ[i] == '}'){
                closecount++;
                if(closecount > 2){
                    oldclosecount = closecount;
                    closecount = 2;
                    right--;
                }
            }
            if(opencount == 2 && closecount == 2){
                if(oldopencount > 2 || oldclosecount > 2){
                    opencount = 0;
                    closecount = 0;
                    oldopencount = 0;
                    oldclosecount = 0;
                    continue;
                }
                left--;
                right = i;
                keys_.push_back(templ.substr(left+2, right-left-3));
                keyleftidx_.push_back(left);
                keyrightidx_.push_back(right);
                opencount = 0;
                closecount = 0;
            }
            else if(opencount == closecount){
                opencount = 0;
                closecount = 0;
            }
        }
    }

    string View::Render(const unordered_map<string, string> &model) const {
        string text = template_;
        long offset = 0;
        for(size_t i = 0; i < keys_.size(); i++){
            auto search = model.find(keys_[i]);
            if(search != model.end()){
                if(search->first == keys_[i]) {
                    if(keyleftidx_[i] + offset >= 0){
                        text.replace(keyleftidx_[i] + offset, keyrightidx_[i] - keyleftidx_[i] + 1, search->second);
                        offset += search->second.size() - (keyrightidx_[i] - keyleftidx_[i] + 1);
                    }
                }
            }
            else{
                if(keyleftidx_[i] + offset >= 0){
                    text.replace(keyleftidx_[i] + offset, keyrightidx_[i] - keyleftidx_[i] + 1, "");
                    offset += 0 - (keyrightidx_[i] - keyleftidx_[i] + 1);
                }
            }
        }
        return text;
    }
}