##пецифікатори формату printf():

    Цілі числа:
        %d — десяткове ціле число зі знаком.
        %u — десяткове беззнакове ціле число.
        %x — шістнадцяткове число (маленькі літери).
        %X — шістнадцяткове число (великі літери).
        %o — вісімкове число.

    Числа з плаваючою точкою:
        %f — число з плаваючою точкою (десяткова форма).
        %e або %E — експоненціальна форма запису числа.
        %g або %G — автоматичний вибір між %f і %e.

    Символи та рядки:
        %c — одиночний символ.
        %s — рядок (масив символів).

    Адреси та покажчики:
        %p — адреса пам’яті у шістнадцятковому вигляді.

    Інші корисні:
        %% — виводить символ %.

##Суфікси для літералів:

 unsigned int a = 10u;        // Беззнакове число
    float b = 3.14f;             // Число типу float
    long double c = 2.71828L;    // Число типу long double
    wchar_t wide_char = L'Ж';    // Широкий символ
    char16_t utf16_char = u'Ж';  // Символ у форматі UTF-16

    printf("a = %u\n", a);
    printf("b = %f\n", b);
    printf("c = %Lf\n", c);
    printf("wide_char = %lc\n", wide_char);
