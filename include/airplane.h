#ifndef AIRPLANE_H
#define AIRPLANE_H


class airplane
{
public:
    airplane();
    ~airplane();

    void setSeat(int _seat);
    int getSeat();

    void setType(const char* _type);
    const char* getType();

protected:

private:
    int seat;
    const char* type;
};

#endif // AIRPLANE_H
