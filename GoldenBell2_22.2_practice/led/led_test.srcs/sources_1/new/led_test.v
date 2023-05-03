`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/11/2023 03:04:40 PM
// Design Name: 
// Module Name: led_test
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module led_test(
    reset,
    led
    );

input reset;
output reg [15:0] led;
        
always @(*)
begin
if(!reset)
    begin
        led <= 16'b0;
    end
else
    begin
        led <= 16'b1111_0000_1111_0000;
    end
end
    
endmodule
