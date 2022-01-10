# push_swap

## Задача 
Написать программу на C, которая вычисляет и отображает в стандартном аутпуте наименьший набор инструкций для сортировки int'ов.

## Инструкции
- Исполняемый файл должен называться *push_swap*
- Необходим Makefile с обычными правилами для компиляции проекта. Перекомпиляция должна происходить только в случае необходимости.
- Используем свою библиотеку libft (у библиотеки свой Makefile). Наш Makefile сначаоа компилирует библиотеку, а потом компилирует проект.
- Глобальные переменные запрещены.
- Проект должен быть написан на C в соответствии с *Norm*.
- Любые ошибки должны обрабатываться. Программа не должна завершаться неожиданым образом. Обязательно освобождение памяти.
- Утечки памяти запрещены.
- Разрешенные функции:
	- `write`
	- `read`
	- `malloc`
	- `free`
	- `exit`

## Основная часть

### Правила игры
- Игра состоит из двух стопок **a** и **b**
- В начале стопка a содержит случайное количество отрицательных или положительных чисел, которые не могут повторяться. Стопка b пустая.
- Цель отсортировать их в порядке возрастания в стопке a.
- Для этого нам доступны следующие операции:
	- **`sa` : swap a** - поменять местами первые два элемента в верхней части стоки a. Ничего не делать, если есть только один элемент или нет элементов.
	- **`sb` : swap b** - поменять местами первые два элемента в верхней части стоки b. Ничего не делать, если есть только один элемент или нет элементов.
	- **`ss` :** - `sa` и `sb` одновременно.
	- **`pa` : push a** - взять первый элемент сверху стопки b и положить его наверх стопки a.Ничего не делать, если b пустая.
	- **`pb` : push b** - взять первый элемент сверху стопки a и положить его наверх стопки b.Ничего не делать, если a пустая.
	- **`ra` : rotate a** - сдвигаем вверх все элементы стопки a на 1. Первый элемент становится последним.
	- **`rb` : rotate b** - сдвигаем вверх все элементы стопки b на 1. Первый элемент становится последним.
	- **`rr` :** - `ra` и `rb` одновременно.
	- **`rra` : reverse rotate a** - сдвигаем вниз все элементы стопки a на 1. Последний элемент становится первым.
	- **`rrb` : reverse rotate b** - сдвигаем вниз все элементы стопки b на 1. Последний элемент становится первым.
	- **`rrr` :** `rra` и `rrb` одновременно.

## Программа *push_swap*

- Нужно написать программу с названием `push_swap`, которая получает как аргумент стопку a в виде списка int'ов. Первый аргумент должен быть вершиной стопки.
- Программа должна показать наименьший список операций для сортировки стека a ( the smallest number being at the top ???? )
- Операции должны быть разделены **только** переносом строки `\n`.
- Цель в том, чтобы отсортровать стопку с минимально возможным колличеством операций. Во время защиты сравнивается количество операций с максимально допустимым значением. Если список операций слишком большой или список не отсортирован должным образом - **FAIL**.
- Если параметры не указаны, программа не должна ничего отображать и подсказывать.
- В случае ошибки дожна показать `Error` и `\n` за ним **on the standard error**. `Errors` включают для примера:
	 - some arguments aren’t integers, 
	 - some arguments are bigger than an integer, 
	 - and/or there are duplicates.
- Во время защиты push_swap будет проверена готовым чекером следующим образом:

`$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l`

`6`

`$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG`

`OK`

`$>`

Если программа **checker_OS** показывет **KO**, наш push_swap завершился со списком операций, которые не сортируют стопку.