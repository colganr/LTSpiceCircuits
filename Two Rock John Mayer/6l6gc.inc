* 6L6GC Beam Power Tube PSpice Model             8/96, Rev. 1.0  (fp)
*
* -------------------------------------------------------------------
*  This model is provided "as is", with no warranty of any kind,
*  either expressed or implied, about the suitability or fitness
*  of this model for any particular purpose.  Use of this model
*  shall be entirely at the user's own risk.
*
*  For a discussion about vacuum tube modeling please refer to:
*  W. Marshall Leach, jr: "SPICE Models for Vacuum-Tube Amplifiers";
*  J. Audio Eng. Soc., Vol 43, No 3, March 1995.
* -------------------------------------------------------------------
*
* This model is valid for the following tubes (within max. ratings):
*                 6L6/G/GA/   5881/
*                 GB, 1614,   6L6WGB,   6L6GC,   7581A,   7027A.
* --------------+-------------------------------------------------
* Plate Dissip. :    19W        23W       30W      35W      35W
* Screen Input  :   2.5W         3W        5W       5W       5W
* Plate Voltage :   360V       400V      500V     500V     600V
* Screen Voltage:   270V       400V      450V     450V     500V
*
* at the following conditions:
*  Plate voltage  : 0..800V
*  Screen voltage : 0..600V
*  Grid voltage   : 0..-60V
*  Cathode current: 0..400mA
*
*
* Connections: Plate
*              | Screen Grid
*              | | Control Grid
*              | | | Cathode
*              | | | |
.SUBCKT  6L6GC P S G K
Esp 2  0  VALUE={V(P,K)+15.15*V(S,K)+134.6*V(G,K)}
E1  3  2  VALUE={7.731E-7*(PWR(V(2),1.5)+PWRS(V(2),1.5))/2}
E2  3  4  VALUE={7.731E-7*PWR(15.15*V(S,K),1.5)*V(P,K)/60}
E3  5  4  VALUE={(1-V(4,2)/ABS(V(4,2)+0.001))/2}
R1  5  0  1.0K
Gk  S  K  VALUE={V(3,2)}
Gp  P  S  VALUE={0.94*(V(3,4)*(1-V(5,4))+V(3,2)*V(5,4))}
Cgk G  K  5P
Cgs G  S  5P
Cgp G  P  0.6P
Cpk P  K  6.5P
.ENDS 6L6GC
