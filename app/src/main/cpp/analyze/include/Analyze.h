//
// Created by 161003 on 2018/8/22.
//

#ifndef FLITETEST_ANALYZE_H
#define FLITETEST_ANALYZE_H

#include <string>
#include <sstream>
#include "Label.h"
namespace engtts
{

    class Analyze
    {
    public:
        LabelsPtr AnalyzeTextFragment(const TextFragmentPtr &fragment);

    private:
        std::string utf8_remove_wide(const std::string &text);
    };
}

#endif //FLITETEST_ANALYZE_H
