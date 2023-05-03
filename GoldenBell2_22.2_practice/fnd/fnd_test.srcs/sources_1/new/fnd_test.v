`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/11/2023 05:49:36 PM
// Design Name: 
// Module Name: fnd_test
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


module fnd_test(
	pcie_ref_clk_p,
	pcie_ref_clk_n,
    reset,
    digit,
    fnd
    );

input									pcie_ref_clk_p;
input									pcie_ref_clk_n;   
input reset;
output reg [3:0] digit;
output reg [7:0] fnd;

reg [15:0] digit_sel;

wire sys_clk;

IBUFDS_GTE2 pcie_ref_clk_ibuf (.O(), .ODIV2(sys_clk), .I(pcie_ref_clk_p), .CEB(1'b0), .IB(pcie_ref_clk_n));

always @(posedge sys_clk or posedge reset)
begin
    if(!reset)
        begin
            digit <= 4'b0000;
            fnd <= 8'b00000011;
            digit_sel <= 0;
        end
    else
        begin
            digit_sel <= digit_sel + 1'b1;
            case(digit_sel)
            0: begin digit <= 4'b1110; fnd <= 8'b00000011; end
            16384: begin digit <= 4'b1101; fnd <= 8'b10011111; end
            32768: begin digit <= 4'b1011; fnd <= 8'b00100101; end
            49152: begin digit <= 4'b0111; fnd <= 8'b00001101; end 
            endcase
        end
end

endmodule
