#include "command.h"
#include <QDebug>

addCommand::addCommand(int *value, QUndoCommand *parent)
{
    /* 使用 Q_UNUSED,避免未使用的数据类型 */
    Q_UNUSED(parent);

    /* undoView 显示的操作信息 */
    setText("Add 1");

    new_count = value;
    old_count = *new_count;
}

void addCommand::redo() {
    *new_count = old_count;
    qDebug()<<"redo:"<<*new_count<<Qt::endl;
}

void addCommand::undo() {
    (*new_count)--;
    qDebug()<<"undo:"<<*new_count<<Qt::endl;
}

addCommand::~addCommand()
{
}
