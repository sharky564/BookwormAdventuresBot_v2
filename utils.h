#ifndef UTILS_H
#define UTILS_H

inline int _max(int a, int b) {
    return a > b ? a : b;
}

inline int _min(int a, int b) {
    return a < b ? a : b;
}

inline int _abs(double num) {
    return num < 0 ? -num : num;
}

inline int _round(double num) {
    return (int)(num + 0.5);
}

inline int _ceil(double num) {
    return ceil(num);
}

#endif // UTILS_H