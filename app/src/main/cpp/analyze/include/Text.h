//
// Created by 161003 on 2018/8/22.
//
#include <string>
#include <vector>
#ifndef FLITETEST_TEXT_H
#define FLITETEST_TEXT_H

namespace engtts
{
    class TextFragment
    {
    private:
        std::string text;

    public:
        TextFragment(const std::string &text);

        const std::string & getText() const
        {
            return text;
        }


    };

    typedef std::shared_ptr <TextFragment> TextFragmentPtr;

    class Text : public std::vector<TextFragmentPtr>
    {
    public:
        Text();

        ~Text();


    };
}

#endif //FLITETEST_TEXT_H
