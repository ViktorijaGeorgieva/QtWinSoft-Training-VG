#ifndef OBLIK_H
#define OBLIK_H

class Oblik{
public:
    virtual double plostina() const = 0;
    virtual bool operator==(const Oblik& o) const = 0;
    virtual ~Oblik() = default;
};

#endif
