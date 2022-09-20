#include "syntaxhighlighter.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent){
    m_lstKeywords << "foreach" << "bool" << "int" << "void" << "double" << "float" << "char"
                  << "delete" << "class" << "const" << "virtual" << "mutable" << "this" << "struct"
                  << "union" << "throw" << "for" << "if" << "else" << "false" << "namespace" << "switch"
                  << "case" << "public" <<" private" << "protected" << "new" << "return" << "using" << "true"
                  <<"->" << ">>" << "<<" << ">" << "<" << "(" << ")" << "{" << "}" << "[" << "]" << "+" << "-"
                  << "*" << "/" << "=" << "!" << "." <<"." << "," << ";" << ":" << "&" << "emit" << "connect" << "SIGNAL"
                  << "|" << "SLOT" << "slots" << "sigmals" << "std" << "cout" << "auto" << "decltype" << "default"
                  << "typename" << "long" << "using" << "while" << "alignas" << "alignof" << "and" << "and_eq" << "asm"
                  << "atomic_cancel" << "atomic_commit" << "atomic_noexcept" << "bitand" << "bitor" << "break" << "catch"
                  << "char8_t" << "char16_t" << "char32_t" << "comp" << "concept" << "consteval" << "constexpr" << "constinit" << "const_cast"
                  << "continue" << "co_await" << "co_return" << "co_yield" << "dynamic_cast" << "enum" << "explicit" << "export" << "extern"
                  <<"friend" << "gotob" << "inline" << "noexcept" << "not" << "not_eq" << "nullptr" << "operator" << "or" << "or_eq" << "reflexpr"
                  << "register" << "reinterpret_cast" << "requires" << "short" << "signed" << "sizeof" << "static" << "static_assert" << "static_cast"
                  <<"struct" << "synchronized" << "template" << "this" << "thread_local" << "try" << "typedef" << "typeid" << "typename" << "unsigned"
                  << "volatile" << "wchar_t" << "xor" << "xor_eq";
}

/* virtual */ void SyntaxHighlighter::highlightBlock(const QString & str){
    int nState = previousBlockState();
    int nStart = 0;
    for (int  i = 0; i < str.length(); ++i){
        if (nState == InsideCStyleComment){
            if (str.mid(i,2) == "*/"){
                nState = NormalState;
                setFormat(nStart , i - nStart + 2 , Qt::darkGray);
                i++;
            }
        }
        else if (nState == InsideCString){
            if (str.mid(i,1) == "\"" || str.mid(i,1) == "\'"){
                if (str.mid( i -1 , 2) != "\\\"" && str.mid(i-1,2) != "\\\'"){
                    nState = NormalState;
                    setFormat(nStart, i-nStart + 1 , Qt::cyan);
                }
            }
        }
        else {
            if (str.mid(i,2) == "//"){
                setFormat(i,str.length() - i ,Qt::darkGray);
                break;
            }
            else if (str.mid(i,1) == "#") {
                setFormat(i , str.length() - i , Qt::green);
                break;
            }
            else if (str.at(i).isNumber()){
                setFormat(i,1,Qt::red);
            }
            else if (str.mid(i,2) == "/*"){
                nStart = i;
                nState  = InsideCStyleComment;
            }
            else if (str.mid(i,1) == "\"" || str.mid(i,1) == "\'"){
                nStart = i;
                nState = InsideCString;
            }
            else {
                QString strKeyword = getKeyword(i , str);
                if (!strKeyword.isEmpty()){
                    setFormat(i , strKeyword.length() , Qt::white);
                    i += strKeyword.length() - 1;
                }
            }

        }
    }
    if (nState == InsideCStyleComment){
        setFormat(nStart , str.length() - nStart , Qt::darkGray);
    }
    if (nState == InsideCString){
        setFormat(nStart , str.length() - nStart , Qt::cyan);
    }
    setCurrentBlockState(nState);
}

QString SyntaxHighlighter::getKeyword(int i, const QString &str) const{
    QString strTemp = "";
    foreach (QString strKeyword, m_lstKeywords){
        if (str.mid(i , strKeyword.length()) == strKeyword){
            strTemp = strKeyword;
            break;
        }
    }
    return strTemp;
}
