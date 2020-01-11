#include <iostream>

#include "document.h"

void document::save(std::ostream& os) const//сохранение в файл элементов коллекции
{
    for (size_t i = 0; i < figures_.size(); ++i)
        figures_[i]->help_print(os);
}

void document::load(std::istream& is)//загрузка из файла элементов коллекции
{
    int help;
    while(is >> help){
        if(help == 1)
        {
            five_angles fig;
            fig.read_file(is);
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<five_angles>(fig);
            figures_.push_back(std::move(new_figure));
        }
        else if(help == 2)
        {
            six_angles fig;
            fig.read_file(is);
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<six_angles>(fig);
            figures_.push_back(std::move(new_figure));
        }
        else if(help == 3)
        {
            eight_angles fig;
            fig.read_file(is);
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<eight_angles>(fig);
            figures_.push_back(std::move(new_figure));
        }
    }
}

void document::add_figure(std::unique_ptr<figure>&& ptr,size_t id)//добавление фигуры в коллекцию; id - место вставки
{
    if (id > this->figures_.size())
    {
        std::cout << "Input index is out of bounds\n";
        return;
    }
    figures_.insert(figures_.begin() + id,std::move(ptr));
    add_command op1;
    std::unique_ptr<add_command> op;
    op=std::make_unique<add_command>(std::move(op1));
    op->id=id;
    op->ptr_ = nullptr;
    operations_.push_back(std::move(op));
}

void document::remove_figure(size_t id)//удаление фигуры из коллекции с заданным индексом
{
    if (id >= this->figures_.size())
    {
        std::cout << "Input index is out of bounds\n";
        return;
    }
    remove_command op1;
    std::unique_ptr<remove_command> op;
    op=std::make_unique<remove_command>(std::move(op1));
    op->id = id;
    op->ptr_=std::move(figures_[id]);
    operations_.push_back(std::move(op));
    figures_.erase(figures_.begin() + id);

}

void document::show(std::ostream &os) const//метод, выводящий объекты, хранящиеся в коллекции, а также их параметры
{
    if(figures_.size()>0)
    {
        for (size_t i = 0; i < figures_.size(); ++i)
        {
            os << "Figure number " << i+1 << "\n";
            os << "Cordinates of figure:";
            figures_[i]->print(os);
            os << "Center: " << figures_[i]->center() << "\n";
            os << "Square: " << figures_[i]->square() << "\n";
        }
    }
}

void document::undo()//отмена последней операции
{
    if(operations_.size()>0)
    {
        operations_[operations_.size()-1]->undo(*this);
        operations_.erase(operations_.begin()+operations_.size()-1);
    }
}

void document::add_command::undo(document &doc)//отмена операции добавления
{
    doc.figures_.erase(doc.figures_.begin() + id);
}

void document::remove_command::undo(document &doc)//отмена операции удаления
{
    doc.figures_.insert(doc.figures_.begin() + id,std::move(ptr_));
}
