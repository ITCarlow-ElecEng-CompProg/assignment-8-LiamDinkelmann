#include <iostream>

using namespace std;
char menu();                                                                                                                        //function declarations
void inverting(double &vc, double &ve, double &vi, double &ri, double &rff, double &a, double &vo);
void noninverting(double &VC, double &VE, double &VI, double &r1, double &r2, double &A, double &VO);
int main()
{
    do{
    switch(menu())
    {
        case 'i':
            {

                double vcc, vee, vin, rin, rf, av=0, vout=0;                                                                        //initialising variables and taking in values from user
                cout<<"Enter value of Vcc: "<<endl;
                cin>>vcc;
                cout<<"Enter value of Vee: "<<endl;
                cin>>vee;
                cout<<"Enter value of Vin: "<<endl;
                cin>>vin;
                do
                {
                    cout<<"Enter value of the input resistor: (Please ensure that this is a positive value)"<<endl;                 //Ensureing rin is gretare than 0
                    cin>>rin;

                }
                while(rin<0);

                do
                {
                    cout<<"Enter value of the feedback resistor: (Please ensure that this is a positive value)"<<endl;              //Ensuring rf is greater than 0
                    cin>>rf;

                }
                while(rf<0);

                inverting(vcc,vee,vin, rin, rf, av, vout);                                                                          //Passing all information to the function

                cout<<"Gain of the amplifier is "<<av<<" and Vout is "<<vout<<"V"<<endl;                                            //Output of result

                break;
            }

        case 'n':
            {

                double VCC, VEE, VIN, R1, R2, AV=0, VOUT=0;
                cout<<"Enter value of Vcc: "<<endl;
                cin>>VCC;
                cout<<"Enter value of Vee: "<<endl;
                cin>>VEE;
                cout<<"Enter value of Vin: "<<endl;
                cin>>VIN;
                do
                {
                    cout<<"Enter value of the resistor 1: (Please ensure that this is a positive value)"<<endl;
                    cin>>R1;

                }
                while(R1<0);

                do
                {
                    cout<<"Enter value of the resistor 2: (Please ensure that this is a positive value)"<<endl;
                    cin>>R2;

                }
                while(R2<0);

                noninverting(VCC,VEE,VIN, R1, R2, AV, VOUT);

                cout<<"Gain of the amplifier is "<<AV<<" and Vout is "<<VOUT<<"V"<<endl;

                break;
            }

        case 'q':
                return 0;
    }
    }
    while(1);

}

char menu()                                                                                                                             //Menu to take in choice from user on task to be accomplished
{
    char choice;

        cout<<" Enter 'i' for an inverting amplifier. \n Enter 'n' for a noninverting amplifier \n Enter 'q' to Quit "<<endl;
        cin>>choice;


return choice;
}

void inverting(double &vc, double &ve, double &vi, double &ri, double &rff, double &a, double &vo)                                      //Function to perform calculations for inverting amplifier
{
    a = -(rff/ri);
    vo = a*vi;
    if(vo<ve)                                                                                                                           //Ensuring the output doesnt go above or below the supply volatges
    {
        vo=ve;
    }
    if(vo>vc)
    {
        vo=vc;
    }
}

void noninverting(double &VC, double &VE, double &VI, double &r1, double &r2, double &A, double &VO)                                    //Function to perfrom calculations for non-inverting amplifier
{
    A = 1+(r2/r1);
    VO = A*VI;
    if(VO>VC)                                                                                                                           //Ensuring the output doesnt go above or below the supply voltages
    {
        VO=VC;
    }

    if(VO<VE)
    {
        VO=VE;
    }


}
