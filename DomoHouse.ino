#include <SoftwareSerial.h>

SoftwareSerial gBluetoothConnection( 0, 1 );
uint8_t gLedStatus[] = { LOW, LOW, LOW, LOW, LOW, LOW };

void SwitchLed( uint8_t );
void SendMessageOnFire( void );
void SendMessageTemperature( void );
void SendMessageError( void );

void setup( void ) {
    gBluetoothConnection.begin( 9600 );
    
    for ( int i = 2; i < 8; i++ ) {
        pinMode( i, OUTPUT );
    }
}

void loop( void ) {
    if ( gBluetoothConnection.available() ) {
        char option = char ( gBluetoothConnection.read() );
        if ( 2 <= option && option <= 7 ) {
            SwitchLed( option - 2 );
        } else if ( option == 0x10 ) {
            SendMessageOnFire();
        } else if ( option == 0x11 ) {
            SendMessageTemperature();
        } else {
            SendMessageError();
        }
    }
}

void SwitchLed( uint8_t ledMatrixId ) {
    gLedStatus[ledMatrixId] = ( gLedStatus[ledMatrixId] ) ? LOW : HIGH;
    digitalWrite( ledMatrixId + 2, gLedStatus[ledMatrixId] );
}

void SendMessageOnFire( void ) {
    if ( digitalRead( A0 ) ) {
        gBluetoothConnection.write( "On fire!" );
    } else {
        gBluetoothConnection.write( "Everything ok!" );
    }
}

void SendMessageTemperature( void ) {
    gBluetoothConnection.write( "Not implemented yet!" );
}

void SendMessageError( void ) {
    gBluetoothConnection.write( "What the fuck was that?" );
}
