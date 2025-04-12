#ifndef CPP_ILEETCODEQUESTION_H
#define CPP_ILEETCODEQUESTION_H

class ILeetCodeQuestion {
public:
    virtual void run() = 0;
    virtual ~ILeetCodeQuestion() = default;
};

#endif //CPP_ILEETCODEQUESTION_H