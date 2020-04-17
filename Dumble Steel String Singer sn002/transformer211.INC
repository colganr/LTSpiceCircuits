* 
* Transformer Specified With Inductance Per Coil
* "Primary" inductance    L1, series resistor R1
* "Secondary" inductance  L2, series resistor R2
* Coupling factor       K12 <=1
* Ideal transformer voltage ratio = SQRT(L2/L1), SQRT(L3/L1)
*
.SUBCKT INTER-TRAFO 1 2 3 4
*
L1 1 2 {L1}  Rser={R1}
L2 3 4 {L2}  Rser={R2}
K12 L1 L2 {K}
*
.ENDS 