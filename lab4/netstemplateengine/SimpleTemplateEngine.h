//
// Created by karol on 3/29/17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <vector>

namespace nets {
    class View {
    public:
        View(std::string templ);
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:
        std::string template_;
        std::vector<std::string> keys_;
        std::vector<size_t> keyleftidx_;
        std::vector<size_t> keyrightidx_;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
