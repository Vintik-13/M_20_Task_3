/*Задание 3. Реализация симуляции игры «Рыбалка»

Что нужно сделать
Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле
реки (river.txt) задаётся список из видов рыб, которые можно в ней поймать.
Рыбок может быть сколько угодно, разных видов. Виды при этом могут повторяться.
В начале программы пользователь указывает, какую именно рыбу он сейчас будет
ловить — вид этой рыбы. После этого из первого файла друг за другом
осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах
вид совпал с указанным пользователем, в выходной файл basket.txt (корзинка)
записывается этот вид.
В конце программы показывается, сколько было поймано рыб за текущую ловлю.
Программу можно запускать несколько раз, при этом уже пойманные рыбы должны
сохраняться в файле-корзинке.*/

#include <iostream>
#include <fstream>
#include <string>

void record_fish_file(const std::string patch, const std::string fish) {

    std::ofstream ofs(patch, std::ios::app);

    if (!ofs.is_open()) {

        std::cout << "File opening error!";
        return;
    }
    else 
        ofs << fish << std::endl;   
}

void search_fish_file(const std::string patch_in, const std::string patch_out, const std::string fish) {

    std::ifstream ifs(patch_out);

    if (!ifs.is_open()) {

        std::cout << "File opening error!";
        return;
    }
    else {

        std::string str;
        while (!ifs.eof()) {

            ifs >> str;
            if (str == fish) {

                record_fish_file(patch_in, fish);
                std::cout << fish << std::endl;
            }                
        }
    }        
}

int main()
{
    std::string patch_out = "river.txt";
    std::string patch_in = "basket.txt";

    std::cout << "Keep a view of the caught fish: ";
    std::string fish;
    std::getline(std::cin, fish);

    search_fish_file(patch_in, patch_out, fish);
}

