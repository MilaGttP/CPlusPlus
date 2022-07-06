# Лабораторна робота з теми "Динамічні структури даних – двозв'язковий список"

#Завдання 1.
Створіть шаблонний клас двозв'язкового списку для роботи з цілими значеннями. Потрібно створити реалізації для типових операцій над елементами:

• AddToHead – додавання елемента до голови;

• AddToTail – додавання елемента до хвоста;

• DeleteFromHead – видалення елемента з голови;

• DeleteFromTail – видалення елемента з хвоста;

• DeleteAll – видалення всіх елементів;

• Show – відображення всіх елементів списку на екрані.

#Завдання 2.
Додати в клас із завдання 1 наступні функції: вставка елемента в задану позицію, видалення елемента по заданій позиції, пошук заданого елемента (функція повертає позицію знайденого елемента у разі успіху або NULL у разі невдачі), пошук та заміна заданого елемента ( функція повертає кількість замінених елементів у разі успіху або -1 у разі невдачі), переворот списку.


# Домашня робота з теми "Динамічні структури даних – двозв'язковий список"

#Завдання 1.
Реалізувати шаблонний клас "Черга" на основі списку.

#Завдання 2.
До існуючого класу двозв'язкового списку додати: операцію клонування списку (функція повинна повертати адресу голови клонованого списку), перевантажити оператор + (оператор повинен повертати адресу голови нового списку, що містить елементи обох списків для яких викликався оператор), перевантажити оператор * (оператор повинен повертати адресу голови нового списку, який містить лише загальні елементи обох списків для яких викликався оператор).

#Завдання 3.
Створити шаблонний клас-контейнер Array, який є масивом, що дозволяє зберігати об'єкти заданого типу. Клас повинен бути реалізований за допомогою двозв'язкового списку. Клас повинен реалізовувати такі функції:

a. GetSize - отримання розміру масиву (кількість елементів, під які виділено пам'ять).

b. SetSize(int size, int grow = 1) — установка розміру масиву (якщо параметр size більший за попередній розмір масиву, то виділяється додатковий блок пам'яті, якщо ні, то "зайві" елементи губляться і пам'ять звільняється); параметр grow визначає для якої кількості елементів необхідно виділити пам'ять, якщо кількість елементів перевищує поточний розмір масиву. Наприклад, SetSize(5, 5); означає, що з додаванні 6-го елемента розмір масиву стає рівним 10, при додаванні 11-го — 15 тощо.

c. GetUpperBound - Отримання останнього допустимого індексу в масиві. Наприклад, якщо при розмірі масиву 10, ви додаєте до нього 4 елементи, то функція поверне 3.

d. IsEmpty - масив порожній?

e. FreeExtra - видалити "зайву" пам'ять (вище останнього допустимого індексу);

f. RemoveAll - видалити все;

g. GetAt - отримання певного елемента (за індексом);

h. SetAt - установка нового значення для певного елемента (індекс елемента повинен бути менше поточного розміру масиву);

i. operator [] - для реалізації двох попередніх функцій;

j. Add - додавання елемента в масив (при необхідності масив збільшується на значення grow функції SetSize);

k. Append - "складання" двох масивів;

l. operator =;

m. GetData - отримання адреси масиву з даними;

n. InsertAt - вставка елемента в задану позицію;

o. RemoveAt — видалення елемента з заданої позиції.
