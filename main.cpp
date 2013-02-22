// The UTF8 Conversion Library is a small library aiding in the converstion from raw text to UTF8 text.
// © Copyright 2010 - 2013 BlackTopp Studios Inc.
/* This file is part of The UTF8 Conversion Library.

    The UTF8 Conversion Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The UTF8 Conversion Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The UTF8 Conversion Library.  If not, see <http://www.gnu.org/licenses/>.
*/
/* The original authors have included a copy of the license specified above in the
   'doc' folder. See 'gpl.txt'
*/
/* We welcome the use of the UTF8 Conversion Library to anyone, including companies who wish to
   Build professional software and charge for their product.

   However there are some practical restrictions, so if your project involves
   any of the following you should contact us and we will try to work something
   out:
    - DRM or Copy Protection of any kind(except Copyrights)
    - Software Patents You Do Not Wish to Freely License
    - Any Kind of Linking to Non-GPL licensed Works
    - Are Currently In Violation of Another Copyright Holder's GPL License
    - If You want to change our code and not add a few hundred MB of stuff to
        your distribution

   These and other limitations could cause serious legal problems if you ignore
   them, so it is best to simply contact us or the Free Software Foundation, if
   you have any questions.

   Joseph Toppi - toppij@gmail.com
   John Blackwood - makoenergy02@gmail.com
*/

#include "utf8conv.h"

#include <iostream>
#include <string>

using namespace std;
using namespace Mezzanine;
using namespace Mezzanine::Unicode;

int main()
{
    Int32 Amount = 0;

    cout << "Binary math components: " << endl;
    cout << AsBitString(High1Bit) << endl;
    cout << AsBitString(High2Bit) << endl;
    cout << AsBitString(High3Bit) << endl;
    cout << AsBitString(High4Bit) << endl;
    cout << AsBitString(High5Bit) << endl;
    cout << AsBitString(High6Bit) << endl;
    cout << AsBitString(High7Bit) << endl;
    cout << AsBitString(High8Bit) << endl << endl;

    cout << AsBitString(Low1Bit) << endl;
    cout << AsBitString(Low2Bit) << endl;
    cout << AsBitString(Low3Bit) << endl;
    cout << AsBitString(Low4Bit) << endl;
    cout << AsBitString(Low5Bit) << endl;
    cout << AsBitString(Low6Bit) << endl;
    cout << AsBitString(Low7Bit) << endl;
    cout << AsBitString(Low8Bit) << endl << endl;

    //
    cout << "Ascii compatible 7 or fewer bits: " << endl;
    char A[5] = "A";
    char APrime[5] = {0,0,0,0,0};
    Int32 AResults = GetCharacterFromInt(APrime,5,65);
    cout << A << ": " << GetIntFromCharacter(Amount,A) << " in " << Amount << " byte" << endl
         << "Should be 65 in 1 byte." << endl
         << "Character from known int: " << APrime << endl
         << "\t With Length/error code: " << AResults << endl << endl;

    //
    cout << "8 bit single byte if it were ascii, two bytes otherwise: " << endl;
    char AE[5] = "Æ";
    char AEPrime[5] = {0,0,0,0,0};
    Int32 AEResults = GetCharacterFromInt(AEPrime,5,198);
    cout << AE << ": " << GetIntFromCharacter(Amount,AE) << " in " << Amount << " bytes" << endl
         << "Should be 198 in 2 bytes." << endl                     //11000110
         << "Character from known int: " << AEPrime << endl
         << "\t With Length/error code: " << AEResults << endl << endl;

    char CWithCedilla[5] = "Ç";
    char CWithCedillaPrime[5] = {0,0,0,0,0};
    Int32 CWithCedillaResults = GetCharacterFromInt(CWithCedillaPrime,5,199);
    cout << CWithCedilla << ": " << GetIntFromCharacter(Amount,CWithCedilla) << " in " << Amount << " bytes" << endl
         << "Should be 199 in 2 bytes." << endl
         << "Character from known int: " << CWithCedillaPrime << endl
         << "\t With Length/error code: " << CWithCedillaResults << endl << endl;

    //
    cout << "2 byte utf8: " << endl;
    char AWithMacron[5] = "Ā";
    char AWithMacronPrime[5] = {0,0,0,0,0};
    Int32 AWithMacronResults = GetCharacterFromInt(AWithMacronPrime,5,256);
    cout << AWithMacron << ": " << GetIntFromCharacter(Amount,AWithMacron) << " in " << Amount << " bytes" << endl
         << "Should be 256 in 2 bytes." << endl
         << "Character from known int: " << AWithMacronPrime << endl
         << "\t With Length/error code: " << AWithMacronResults << endl << endl;

    char GWithCircumflex[5] = "Ĝ";
    char GWithCircumflexPrime[5] = {0,0,0,0,0};
    Int32 GWithCircumflexResults = GetCharacterFromInt(GWithCircumflexPrime,5,284);
    cout << GWithCircumflex << ": " << GetIntFromCharacter(Amount,GWithCircumflex) << " in " << Amount << " bytes" << endl
         << "Should be 284 in 2 bytes." << endl
         << "Character from known int: " << GWithCircumflexPrime << endl
         << "\t With Length/error code: " << GWithCircumflexResults << endl << endl;

    //
    cout << "3 byte utf8: " << endl;
    char EquivalentTo[5] = "≍";
    char EquivalentToPrime[5] = {0,0,0,0,0};
    Int32 EquivalentToResults = GetCharacterFromInt(EquivalentToPrime,5,8781);
    cout << EquivalentTo << ": " << GetIntFromCharacter(Amount,EquivalentTo) << " in " << Amount << " bytes" << endl
         << "Should be 8781 in 3 bytes." << endl
         << "Character from known int: " << EquivalentToPrime << endl
         << "\t With Length/error code: " << EquivalentToResults << endl << endl;

    char CJKCompatibilityIdeograph2FA04[5] = "餩";
    char CJKCompatibilityIdeograph2FA04Prime[5] = {0,0,0,0,0};
    Int32 CJKCompatibilityIdeograph2FA04Results = GetCharacterFromInt(CJKCompatibilityIdeograph2FA04Prime,5,39209);
    cout << CJKCompatibilityIdeograph2FA04 << ": " << GetIntFromCharacter(Amount,CJKCompatibilityIdeograph2FA04) << " in " << Amount << " bytes" << endl
         << "Should be 39209 in 3 bytes." << endl
         << "Character from known int: " << CJKCompatibilityIdeograph2FA04Prime << endl
         << "\t With Length/error code: " << CJKCompatibilityIdeograph2FA04Results << endl << endl;

    //
    char KingOfClubs[5] = "🃞";
    char KingOfClubsPrime[5] = {0,0,0,0,0};
    Int32 KingOfClubsResults = GetCharacterFromInt(KingOfClubsPrime,5,127198);
    Int32* Test = (Int32*)KingOfClubsPrime;
    cout << "X" << AsBitString(*Test) << "X" << endl;
    Test = (Int32*)KingOfClubs;
    cout << "A" << AsBitString(*Test) << "A" << endl;
    cout << KingOfClubs << ": " << GetIntFromCharacter(Amount,KingOfClubs) << " in " << Amount << " bytes" << endl
         << "Should be 127198 in 4 bytes." << endl
         << "Character from known int: " << KingOfClubsPrime << endl
         << "\t With Length/error code: " << KingOfClubsResults << endl << endl;

    return 0;
}

