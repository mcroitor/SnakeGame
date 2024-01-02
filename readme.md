# Snake Game

Данный проект представляет собой пример 3ей лабораторной по предмету **_Программирование на языке С++_**.

В рамках данной работы были определены конструкторы для всех типов данных, представляющих данные игры, а также операторы копирования и сравнения. Также были добавлены / исправлены реализации методов в ряде классов, обновлён файл сборки.

## Правила игры

## Описание структуры

* `Apple` - класс для определения яблок.
* `Board` - Класс доски.
* `Direction` - направление движения змейки, принимает значения `top`, `bottom`, `left`, `right`.
* `GameEngine` - движок игры.
* `Painter` - класс для отрисовки игровых объектов.
* `Point` - точка (позиция) на доске.
* `Snake` - собственно змея.

## Зависимости

Для сборки проекта необходимо иметь установленные:

* `g++` - компилятор С++, рекомендуемая версия 10 или выше
* `make` - система автоматизации сборки, рекомендуемая версия 4 или выше

## Сборка

1. Откройте консоль;
2. Склонируйте проект;
3. Перейдите в папку проекта;
4. Выполните сборку.

```shell
git clone git@github.com:mcroitor/SnakeGame.git
cd SnakeGame
make
```
