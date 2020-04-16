* Voltage Controlled Resistance Negative Slope, absolute voltage
* 
* VCRAbs: Voltage Controlled Resistor, controlled by the absolute value of control voltage.
* Behaves like a light dependent resistor, driven by a light that is not sensitive to the 
* polatity of the control voltage.
* 
* Jim Ryan 2011
*
* VT Threshold of the lowest Control Voltage that starts changing resistance.
* VM Maximun Control Voltage that changes resistance.
* RD Maximum Resistance, Resistance where Control Voltage is less than VT
* RL Minimum Resistance, Resistance where Control Voltage is greater than VM
*
.SUBCKT VCRAbs Ctl1 Ctl0 Rload Rload0;  
+ Rlight={RL} Rdark={RD} Vmax={VM} Vthresh={VT}
RD Rload Rload0 {Rdark}
B1 Rload Rload0 I=V(Rload,Rload0)*(max(0,(min(Vmax,abs(V(Vin,Ctl0)))-{Vthresh})/({Vmax}-{Vthresh}))/(({Rdark}*{Rlight})/({Rdark}-{Rlight})))
E1 Vin Ctl0 Ctl1 Ctl0 1
.ENDS
                                               