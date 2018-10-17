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

//item ParseOneRow(QString row);
float distance(Point A, Point B);
float perimeter(Point Array[4], int len);
float area(Point Array[4], int len);//Geron

float deter(Point A, Point B);

float cross(Point Array[4]);

void bound(Point Array[], int len, Point Box[]);

void writeFile (Point Array[], float &per, float &area, int len);
int ReadFile (Point Array[],QString ReadFileName);

QString printQuad(Point Array[4]);


int main()

{
    //float perim=0;
    //float ar=0;
   // Point quadOne[4];
   float distance(distance);
   float perimeter(perimeter);
   float area(area);
   float deter(deter);
   float cross(cross);
   void bound();
    void writeFile();
    int ReadFile (ReadFile);


    //QString ReadFileName = "Points.txt";

    //QFile resFile ("Results.txt");
    //resFile.remove();




  /*  qDebug() << printQuad(quadOne);
    QString qsRetVal = "Quadrilateral with points: A[0;0] B[4;0] C[4;4] B[0;4] "  "Have perimeter %1 and area %2";
    float perim,ar;
     perim = perimeter(quadOne);
     ar = area (quadOne);
     qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
     qDebug() << qsRetVal;




    }*/
/*QString printQuad(Point Arr[4])
{
    QString qsRetVal = "Quadrilateral with points: ";
    QString qsTemp;
    Point curPoint;
    for (int i=0; i<4; i++){
        qsTemp = "%1[%2;%3] ";
        curPoint = Arr[i];
        qsTemp=qsTemp.arg(curPoint.Name).arg(curPoint.x).arg(curPoint.y);
        qsRetVal.append(qsTemp);

 }  }   return qsRetVal;*/
}
float distance(Point A, Point B){
    float dis = sqrt(pow((A.x-B.x),2) +pow((A.y-B.y),2));
    return dis;

}


float perimeter(Point Array[4], int len){


    Point A[5];
    int i=0;
    for (; i<4; i++)A[i]=Array[i];
    A[i]=Array[0];
    float ret=0;
    for (i=0; i<4; i++) ret+=distance(A[i],A[i+1]);
    return ret;
   /* float per=0;
    for(int i=0;i<len-1;++i){
        per = per + distance(Array[i], Array[i+1]);
                i++;
        per= per+distance(Array[i],Array[0]);*/

    }
    //float per = distance(Array[0]+Array[1]+Array[2]+Array[3]);

   /* cout<<"The perimeter of the tetragon is " << per << ";" << endl;
    return per;*/


float deter(Point A, Point B)
{
    return ((A.x*B.y) - (A.y*B.x));
}


float area(Point Array[4],int len)
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
    //Point Z={0.0, 0.0,'z'};
    float det=0;
    QString qsTemp;
    for (i=0; i<4; i++) {
        det = distance(A[i],A[i+1]);
        qsTemp= "distance for [%1,%2] : [%3,%4] is %5";
        qsTemp= qsTemp.arg(A[i].x).arg(A[i].y).arg(A[i+1].x).arg(A[i+1].y).arg(det);
        qDebug() << qsTemp;
    }
    return det;
}

        //{
    /*float area = abs(0.5*(Array[0].x*Array[1].y+Array[1].x*Array[2].y
            +Array[2].x*Array[3].y+Array[3].x*Array[0].y-
            Array[1].x*Array[0].y-Array[2].x*Array[1].y-
            Array[3].x*Array[2].y-Array[0].x*Array[3].y));*/
   /* int i = 0;
    float area = 0;
    while(i<len-1){
        area = area + (Array[i].x*Array[i+1].y-Array[i+1].x*Array[i].y);
        i++;
    }
    area = abs(0.5*(area + (Array[i].x*Array[0].y-Array[0].x*Array[i].y)));
    cout << "The total area of the tatragon is " << area << ";" << endl;
    return area;
    //return 16.0;
}*/

void bound(Point Array[], int len, Point Box[])
{
    float top, bottom, left, rigt;
    Point CP = Array[0]; // curPoint;
    top = CP.y;
    bottom = CP.y;
    left = CP.x;
    rigt = CP.x;
    for (int i=1; i<len; i++) {
        CP = Array[i];

        if (top<CP.y) top=CP.y;
        if (bottom>CP.y) bottom=CP.y;

        if (left>CP.x) left=CP.x;
        if (rigt<CP.x) rigt=CP.x;

    }
    Box[0].x=left;
    Box[0].y=top;

    Box[1].x=rigt;
    Box[1].y=bottom;
}


void writeFile (Point Array[], float &per, float &area,int len){


    QString qsOutFileName = "Results.txt";
    QFile resFile (qsOutFileName);
    if (resFile.open(QFile::WriteOnly |QFile::Append )){
        QTextStream out(&resFile);
        out<<"Points coordinates\r\n";
        for (int i=0; i<len; i++){
            out<<"Point "<<Array[i].Name<<": ["<<Array[i].x<<";"<<Array[i].y<<"]\r\n";
        }
        out<<"Figure perimeter: "<<per<<"\r\n";
        out<<"Figure area: "<<area<<"\r\n";


        out<<"\r\n";
    }
}
int ReadFile(Point Array[],QString ReadFileName){

         QString message;
        //QString ReadFileName = "Points.txt";

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



        // item AllItems[20];

      QString oneLine = inputConsole.readLine();
           QString qsTemp = "A:%1 B:%2 C:%3 D%4 \n";
        int i=0;
        int N=0;
        float x, y, Name;
        QString qsDesc;
        while (!inputConsole.atEnd()) {
            i++;
            //qsTemp=qsTemp.arg(i,3,10, QChar(' ')).arg(oneLine);
            //cout << qUtf8Printable(qsTemp);
            if (i<2) {
                cout << qUtf8Printable(oneLine) << endl;
                oneLine = inputConsole.readLine();
            } else {
            inputConsole >> x;
            inputConsole >> y;
            inputConsole >> Name;

            qsDesc = inputConsole.readLine();

             //in>>qsDesc;


            qsTemp = "x:%1 y:%2 Name:%3  \n";
            qsTemp=qsTemp.arg(x).arg(y).arg(Name).arg(qsDesc);

            cout << qUtf8Printable(qsTemp)<<endl;
            }

           /* if (oneLine.contains('.')) {
                        AllItems[N]= ParseOneRow(oneLine);
                        N++;
                    }
                    qsTemp = "%1 : %2 \n";}*/

             file.close();
}}
