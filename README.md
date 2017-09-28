## Курсовая работа по дисциплине ТРПО. СибГУТИ
`rep:` [github.com/kristintv/trpo_project](https://github.com/kristintv/trpo_project)

* `Составление ТЗ:` Маргарита Орлова, Кристина Тогочакова
* `Разработка ПО:` Кристина Тогочакова
* `Тестирование ПО:` Маргарита Орлова
* `Управление проектом:` Маргарита Орлова
* `Team lead:` Маргарита Орлова

***

### Framework
**Необходима установка пакетов ncurses для работы приложения:**
1. libncurses5 
1. libncurses5-dev 
1. libncursesw5-dev 
1. libncursesw5

`sudo apt-get install libncurses5 libncurses5-dev libncursesw5-dev libncursesw5`

### Compile
**При компиляции указать ключ `-lncurses`**

* Компиляция: `gcc bc_game.c -std=c11 -lncurses -o BullsAndCows`
* Запуск: `./BullsAndCows`
