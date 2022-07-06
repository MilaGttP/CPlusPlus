# Лабораторна робота з теми "Успадкування"

#Завдання 1.
Створіть клас Student, який міститиме інформацію про студента. За допомогою механізму успадкування, реалізуйте клас. Aspirant (аспірант – студент, який готується до захисту кандидатської роботи), похідний від Student.

#Завдання 2.
Створіть клас Passport (паспорт), який міститиме паспортну інформацію про громадянина України.
За допомогою механізму успадкування реалізуйте клас ForeignPassport (закордонний паспорт) похідний від Passport.
Нагадаємо, що закордонний паспорт містить крім паспортних даних, також дані про візи, номер закордонного паспорта.

#Завдання 3.
Створити абстрактний базовий клас «Транспортний засіб»
та похідні класи «Автомобіль», «Велосипед», «Візок». Підрахувати час та вартість перевезення пасажирів та вантажів
кожним транспортним засобом.


# Домашня робота з теми "Успадкування"

#Завдання 1.
Створити базовий клас «Домашня тварина» та похідні класи «Собака», «Кішка», «Папуга». За допомогою конструктора встановити ім'я кожної тварини та її характеристики.

#Завдання 2.
Описати базовий клас «Рядок».
Методи:

1) конструктор без параметрів;

2) конструктор, що приймає як параметр C-рядок (закінчується нульовим байтом);

3) конструктор копіювання;

4) оператор присвоєння;

5) отримання довжини рядка;

6) очищення рядка (зробити рядок порожнім);

7) деструктор;

8) конкатенація рядків (перевантажити оператори + та +=);

9) перевірка на рівність (= =) та на нерівність (!=).

Описати клас «Бітовий рядок» похідний від класу «Рядок» (Рядки цього класу можуть містити лише символи '0' та '1'). Якщо в основі рядка, що ініціалізує,
зустрінуться будь-які символи, відмінні від допустимих, то «Бітовий рядок» стає порожнім. Вміст рядка сприймається як двійкове уявлення цілого числа зі знаковим розрядом. Негативні числа зберігаються у додатковому коді.

Методи:

1) конструктор без параметрів;

2) конструктор, що приймає як параметр C-рядок;

3) конструктор копіювання;

4) оператор присвоєння;

4) деструктор;

5) зміна знака числа (переведення числа до додаткового коду).

8) складання бітових рядків (перевантажити оператори +

та +=);

9) перевірка на рівність (= =) та на нерівність (!=).
