//
// Created by 161003 on 2018/8/22.
//
#include <string>
#include "Text.h"

#ifndef FLITETEST_LABELS_H
#define FLITETEST_LABELS_H

namespace engtts
{
    class Label
    {
    private:
        TextFragmentPtr textFragment;      ///< link to the text fragment from which this element was generated.

    public:
        Label(){};

        virtual ~Label(){};

        /**
         * Return a reference to the label in HTK format.
         **/
        virtual const std::string &getAsHTKLabel() = 0;

        inline virtual void SetTextFragment(const TextFragmentPtr &textFragment)
        {
            this->textFragment = textFragment;
        }
    };

    class HTKLabel : public Label
    {
    private:
        std::string htkLabel;
    public:
        HTKLabel(const std::string &htklab)
        {
            htkLabel = htklab;
        }

        inline virtual const std::string &getAsHTKLabel()
        {
            return htkLabel;
        }

        virtual ~HTKLabel() {}
    };

    typedef std::shared_ptr<Label> LabelPtr;

    class Labels : public std::vector<LabelPtr>
    {
    public:
        Labels() {}

        ~Labels() {}

    };

    typedef std::shared_ptr<Labels> LabelsPtr;




}
#endif //FLITETEST_LABELS_H
