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
    if (_abs((int)num - num) < 1e-4) { // note that this error is sufficient for the scale at which we are working
        return (int)num;
    }
    return (int)num + 1;
}

#endif // UTILS_H