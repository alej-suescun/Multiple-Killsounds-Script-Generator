#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;


void creadorDeArchivos3000(bool IsMvM, int nKillsounds) {
    string nombre;
    string pathArchivo = "scripts/";
    string archivo;

    // Crea la subcarpeta
    if (!filesystem::exists(pathArchivo)){
        filesystem::create_directory(pathArchivo);
    }

    if (IsMvM){
        nombre = "mvm_level_sounds.txt";
    } 
    else{
        nombre = "game_sounds_weapons.txt";
    }

    archivo = pathArchivo+nombre;

    ofstream Archivo(archivo);

    //COMENTARIO
    Archivo<<"// ARCHIVO GENERADO AUTOMATICAMENTE"<<endl;
    Archivo<<"// SCRIPT: https://github.com/alej-suescun/Multiple-Killsounds-Script-Generator"<<endl;
    Archivo<<"// POR: ASD++"<<endl<<endl;

    //LO IMPORTANTE
    Archivo<<"\"Player.KillSoundDefaultDing\""<<endl;
    Archivo<<"{"<<endl;
    Archivo<<"	\"channel\"		\"CHAN_STATIC\""<<endl;
    Archivo<<"	\"volume\"		\"1\""<<endl;
    Archivo<<"	\"soundlevel\"		\"SNDLVL_NONE\""<<endl;
    Archivo<<"	\"pitch\"		\"PITCH_NORM\""<<endl;
    Archivo<<"	\"rndwave\""<<endl;
    Archivo<<"    {"<<endl;
    //LOS KILLSOUNDS
    Archivo<<"        \"wave\" \")ui/killsound.wav\""<<endl;
    for (int i = 2; i <= nKillsounds; i++)
    {
        Archivo<<"        \"wave\" \")ui/killsound"<<i<<".wav\"\n";
    }
    //FIN DEL ARCHIVO
    Archivo<<"    }"<<endl;
    Archivo<<"}"<<endl;

    Archivo.close();
}

int main () {
    int nKillsounds = 0;
    cout<<"INGRESE CUANTOS KILLSOUNDS SON: ";
    cin>>nKillsounds;
    cout<<endl;

    cout<<"GENERANDO ARCHIVOS..."<<endl;

    creadorDeArchivos3000(false, nKillsounds);
    cout<<"ARCHIVO \"game_sounds_weapons.txt\" CREADO"<<endl;

    creadorDeArchivos3000(true, nKillsounds);
    cout<<"ARCHIVO \"mvm_level_sounds.txt\" CREADO"<<endl;

    cout<<"LOS ARCHIVOS SE CREARON CORRECTAMENTE"<<endl;

    system("pause");
    return 0;
}
