## Annotation
This program is a bmp V3 image handler. At the input of the program in the console line are given keys and arguments to perform certain functions.

## Program launch
1. Clone the repository
2. Go to the src folder
3. Run command 'make'. This will produce the 'picture_handler' executable.
4. Run the 'file picture_handler'.

## Program operation
To get acquainted with the keys, you need to run the file with the -h switch. The console will display information about all the keys that are used in the program. All keys of the program can be found in [file](keys.md).

The program implements the following bmp-file processing functionality:
1. Drawing a square with diagonals. The square is defined:
- The coordinates of the upper left corner
- Side size
- line thickness
- line color
- Can be filled or not (diagonals are placed “on top” of the fill)
- The color with which it is filled, if the user selects filled
2. Filter rgb component. This tool should allow for the entire image either to be set to 0 or to be set to 255 by the value of the given component. The functionality is defined:
- Which component needs to be changed
- In what value it needs to be changed
3. Rotate the image (part) by 90/180/270 degrees. The functionality is defined:
- The coordinates of the upper left corner of the area
- The coordinates of the lower right corner of the area
- Angle of rotation
4. Drawing a circle. The circle is defined:
- either by the coordinates of the upper left and lower right corner of the square in which it is inscribed, or by the coordinates of its center and radius
- thickness of the circle line
- circle line color
- the circle can be filled or not
- the color with which the circle itself is filled, if the filled circle is selected by the user

## Launch examples

 `./picture_handler --InputFile ../Pictures/simpsonsvr.bmp -i`
 
 `./picture_handler -s --InputFile ../Pictures/simpsonsvr.bmp --X_UpLeft 100 --Y_UpLeft 200 --Length 200 --Width 25 -r 255 --Green 0 -b 255 --OutputFile 12.bmp`
 
 `./picture_handler -t --InputFile ../Pictures/witcher3.bmp --X_UpLeft 100 --Y_UpLeft 300 --X_DownRight 200 --Y_DownRight 500 --Alpha 90 --OutputFile 12.bmp`
 
 `./picture_handler -f --InputFile ../Pictures/simpsonsvr.bmp --Component Green --Component_Value 255 --OutputFile 12.bmp`
 
 `./picture_handler -c --InputFile ../Pictures/simpsonsvr.bmp -o 1 --X_UpLeft 100 --Y_UpLeft 200 --X_DownRight 300 --Y_DownRight 400 --Width 35 --Red 255 -g 0 --Blue 0 --OutputFile 12.bmp`


Examples of the program can be found in [folder](https://github.com/jendos2001/C_Pictures_handler/tree/main/Examples).


## Аннотация
Данная программа представляет собой обработчик изображений формата bmp V3. На вход программе в консольной строке подаются ключи и аргументы для выполнения тех или иных функций.

## Запуск программы
1. Склонировать репозиторий
2. Перейти в папку src
3. Выполнить команду make. Получится исполняемый файл picture_handler.
4. Запустить файл picture_handler.

## Работа программы
Чтобы ознакомится с ключами, требуется запустить файл с ключом -h. В консоль будет выведена информация о всех ключах, которые используются в программе. Со всеми ключами программы можно ознакомится в [файле](keys.md).

Программа реализовывает следующий функционал по обработке bmp-файла:
1. Рисование квадрата с диагоналями. Квадрат определяется:
	- Координатами левого верхнего угла
	- Размером стороны
	- Толщиной линий
	- Цветом линий
	- Может быть залит или нет (диагонали располагаются “поверх” заливки)
	- Цветом которым он залит, если пользователем выбран залитый
2. Фильтр rgb-компонент. Этот инструмент должен позволять для всего изображения либо установить в 0 либо установить в 255 значение заданной компоненты. Функционал определяется:
	- Какую компоненту требуется изменить
	- В какой значение ее требуется изменить 
3. Поворот изображения (части) на 90/180/270 градусов. Функционал определяется:
	- Координатами левого верхнего угла области
	- Координатами правого нижнего угла области
	- Углом поворота 
4. Рисование окружности. Окружность определяется:
	- либо координатами левого верхнего и правого нижнего угла квадрата, в который она вписана, либо координатами ее центра и радиусом
	- толщиной линии окружности
	- цветом линии окружности
	- окружность может быть залитой или нет
	- цветом которым залита сама окружность, если пользователем выбрана залитая окружность

## Примеры запуска

 `./picture_handler --InputFile ../Pictures/simpsonsvr.bmp -i`
 
 `./picture_handler -s --InputFile ../Pictures/simpsonsvr.bmp --X_UpLeft 100 --Y_UpLeft 200 --Length 200 --Width 25 -r 255 --Green 0 -b 255 --OutputFile 12.bmp`
 
 `./picture_handler -t --InputFile ../Pictures/witcher3.bmp --X_UpLeft 100 --Y_UpLeft 300 --X_DownRight 200 --Y_DownRight 500 --Alpha 90 --OutputFile 12.bmp`
 
 `./picture_handler -f --InputFile ../Pictures/simpsonsvr.bmp --Component Green --Component_Value 255 --OutputFile 12.bmp`
 
 `./picture_handler -c --InputFile ../Pictures/simpsonsvr.bmp -o 1 --X_UpLeft 100 --Y_UpLeft 200 --X_DownRight 300 --Y_DownRight 400 --Width 35 --Red 255 -g 0 --Blue 0 --OutputFile 12.bmp`


Примеры работы программы можно посмотреть в [папке](https://github.com/jendos2001/C_Pictures_handler/tree/main/Examples)
