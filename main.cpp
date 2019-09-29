#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using  namespace cv;
int main( int argc, char** argv )
{
    // задаём высоту и ширину картинки
    int height = 440;
    int width = 800;
    // задаём точку для вывода текста
    Point pt = Point( height/4, width/2 );
    // Создаёи 8-битную, 3-канальную картинку и заливаем картинку чёрным цветом
    Mat hw(height, width, CV_8UC3, Scalar(0,0,0));
    // инициализация шрифта
    // используя шрифт выводим на картинку текст
    putText(hw,
            "OpenCV Step By Step",
            pt,
            FONT_HERSHEY_PLAIN,
            3,
            Scalar(150,0,150),
            4);
    // создаём окошко
    namedWindow("Hello World", 0);
    // показываем картинку в созданном окне
    imshow("Hello World", hw);
    // ждём нажатия клавиши
    waitKey(0);

    // освобождаем ресурсы
    return 0;
}