//
// Created by 161003 on 2018/8/22.
//

#include "Text.h"

namespace engtts
{
    Text::~Text()
    {

    }

    Text::Text()
    {

    }


    TextFragment::TextFragment(const std::string &text)
    {
        if (text.size() >= 3 && text[0] == '\xEF'
            && text[1] == '\xBB' && text[2] == '\xBF')
        {
            this->text = text.substr(3);
        }
        else
        {
            this->text = text;
        }


    }




}