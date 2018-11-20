#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <iostream>
using namespace std;



struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B);
float perimeter(Point Array[4]);
float area(Point Array[4]);
float deter(Point A, Point B);
float cross(Point Array[4]);
int ReadFile (Point Array[],QString ReadFileName);
void writeFile (Point Array[],Point A,Point B, float &distance ,float &perimeter,float area, float cross);

int main(){

   float distance(distance);
   float perimeter(perimeter);
   float area(area);
   float deter(deter);
   float cross(cross);
   void bound();
   int ReadFile (Point Array[],QString ReadFileName);
   void writeFile(Point Array[], float &per, float &area, float &dis, float &deter);
}
float distance(Point A, Point B){
    float dis = sqrt(pow((A.x-B.x),2) +pow((A.y-B.y),2));
    return dis;
}
float perimeter(Point Array[4]){

    Point A[5];
    int i=0;
    for (; i<4; i++)A[i]=Array[i];
    A[i]=Array[0];
    float ret=0;
    for (i=0; i<4; i++) ret+=distance(A[i],A[i+1]);
    return ret;

}

float deter(Point A, Point B)
{
    return ((A.x*B.y) - (A.y*B.x));
}


float area(Point Array[4])
{
    Point A[5];
    int i=0;
    for (; i<4; i++)A[i]=Array[i];
    A[i]=Array[0];
    float ret=0;
    float det=0;
    QString qsTemp;
    for (i=0; i<4; i++) {
        det = deter(A[i],A[i+1]);
        qsTemp= "Deter for [%1,%2] : [%3,%4] is %5";
        qsTemp= qsTemp.arg(A[i].x).arg(A[i].y).arg(A[i+1].x).arg(A[i+1].y).arg(det);
        qDebug() << qsTemp;
        ret+=det;
    }
    return fabs(ret/2.0);
}

float cross(Point Array[4])
{
    Point A[5];
    int i=0;
    for (; i<4; i++)A[i]=Array[i];
    A[i]=Array[0];
    float det=0;
    QString qsTemp;
    for (i=0; i<4; i++) {
        det = distance(A[i],A[i+1]);
        qsTemp= qsTemp.arg(A[i].x).arg(A[i].y).arg(A[i+1].x).arg(A[i+1].y).arg(det);
        qDebug() << qsTemp;
    }
    return det;
}

void writeFile (Point Array[],Point A,Point B, float &distance ,float &perimeter,float area, float cross){
    QFile resFile ("Results.txt");
    if (resFile.open(QFile::WriteOnly |QFile::Append )){
        QTextStream out(&resFile);
        out<<"Points coordinates is \r\n";
        out<<"Array is "<<Array<< endl;
        out<<"Distance is "<<distance<<"Perimeter is "<<perimeter<<"Determinate is "<<deter<< "Area is "<<area<< "Cross is " <<cross;
        out<<"\r\n";

    }
}
int ReadFile(Point Array[]){
    QString message;
    QString ReadFileName ="Points.txt";
    QFile file(ReadFileName);

         if (!file.exists()){
             message = "Can't find file %1 to read\n";
             message = message.arg(ReadFileName);
             qDebug() << message;
             return -1;
    }

         if(!file.open(QFile::ReadOnly | QFile::Text))  {
             message = "Can't open the file %1 for reading\n";
              message = message.arg(ReadFileName);
              qDebug() << message;
              return -1;
    }

        QTextStream inputConsole(&file);
        inputConsole.setAutoDetectUnicode(true);
        inputConsole.setCodec("UTF-8");
        system("chcp 65001");

      QString oneLine = inputConsole.readLine();

        int i=0;
        float x, y;
        char Name;
        inputConsole >> x;
        inputConsole >> y;
        inputConsole >> Name;
        cout<<x<<" "<<y<<" "<<Name<<" "<<endl;


        while (!inputConsole.atEnd()) {
            i++;

            inputConsole >> x;
            inputConsole >> y;
            inputConsole >> Name;
            cout<<x<<"-X "<<y<<"-Y "<<Name<<"- Name "<<endl;
            Point Array;
            Point A[i];
            Point B[i];




            A[i].x=x;
            A[i].y=y;
            B[i].x=x;
            B[i].y=y;
            distance(A,B);
            perimeter(A);
            area(A);
            cross(A);
            writeFile(Array,A,B,distance,perimeter,area, cross);



            }


             file.close();
}
