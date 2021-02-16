unsigned char Digits(signed long Number, const unsigned char Base) {
    register unsigned char Digits = 1;
    while ((Number /= Base)) {
        Digits++;
    }
    return Digits;
}
char *IntToStr(char *Dest, signed long Number, const unsigned char Base, unsigned char Digits) {
    unsigned long N = Number;
    if (Number < 0) {
        *Dest++ = '-';
        N = -Number;
    }
    while (Digits--) {
        const ldiv_t Div = ldiv(N, Base);
        Dest[Digits] = (Div.rem < 10? '0' : 'A'-10)+(unsigned char)Div.rem;
        N = Div.quot;
    }
    return Dest;
}
