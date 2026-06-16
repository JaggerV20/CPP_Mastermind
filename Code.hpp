#ifndef CODE_H
#define CODE_H

class Code {
    public:
        Code(int color1, int color2, int color3, int color4);
        int* getCode();
        int* equals(Code codeToCompare);
};

#endif