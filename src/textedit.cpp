#include "TextEdit.h"

TextEdit::TextEdit(QTextEdit* ptxt) : QTextEdit(ptxt)
{
    QFont fnt("Lucida Console" , 14 , QFont::Normal);
    this -> document()->setDefaultFont(fnt);

    new SyntaxHighlighter(this -> document());

    QPalette pal = this -> palette();
    pal.setColor(QPalette::Base , Qt::darkBlue);
    pal.setColor(QPalette::Text , Qt::yellow);
    this -> setPalette(pal);

}
