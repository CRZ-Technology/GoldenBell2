# PCIe
# (begin)
create_clock -period 10.000 -name PCIe_RefClock_100MHz -waveform {0.000 5.000} [get_ports pcie_ref_clk_p]

set_false_path -through [get_ports pcie_perst_n]

set_false_path -from [get_clocks clk_fpga_0] -to [get_clocks *userclk2]
set_false_path -from [get_clocks *userclk2] -to [get_clocks clk_fpga_0]
set_false_path -from [get_clocks clk_fpga_1] -to [get_clocks *userclk2]
set_false_path -from [get_clocks *userclk2] -to [get_clocks clk_fpga_1]
set_false_path -from [get_clocks clk_125mhz_mux_x0y0] -to [get_clocks clk_fpga_0]
set_false_path -from [get_clocks clk_fpga_0] -to [get_clocks clk_125mhz_mux_x0y0]
set_false_path -from [get_clocks clk_250mhz_mux_x0y0] -to [get_clocks clk_fpga_0]
set_false_path -from [get_clocks clk_fpga_0] -to [get_clocks clk_250mhz_mux_x0y0]
set_false_path -from [get_clocks clk_fpga_1] -to [get_clocks clk_fpga_0]
set_false_path -from [get_clocks clk_fpga_0] -to [get_clocks clk_fpga_1]
## (end)

set_property PACKAGE_PIN U9 [get_ports pcie_ref_clk_p]
set_property PACKAGE_PIN V9 [get_ports pcie_ref_clk_n]

set_property IOSTANDARD LVCMOS33 [get_ports pcie_perst_n]
set_property PACKAGE_PIN U16 [get_ports pcie_perst_n]
set_property PULLUP true [get_ports pcie_perst_n]

set_property PACKAGE_PIN AB22 [get_ports user_lnk_up_0]
set_property IOSTANDARD LVCMOS33 [get_ports user_lnk_up_0]

set_false_path -from [get_pins design_1_i/NVMeHostController4L_0/inst/pcie_7x_0_core_top_inst0/inst/inst/pcie_top_i/pcie_7x_i/pcie_block_i/PIPECLK] -to [get_pins {design_1_i/NVMeHostController4L_0/inst/user_top_inst0/reg_cpu_pcie_sync_isnt0/r_pl_ltssm_state_reg[*]/D}]
set_false_path -from [get_pins design_1_i/NVMeHostController4L_0/inst/pcie_7x_0_core_top_inst0/inst/inst/pcie_top_i/pcie_7x_i/pcie_block_i/PIPECLK] -to [get_pins design_1_i/NVMeHostController4L_0/inst/user_top_inst0/reg_cpu_pcie_sync_isnt0/r_pl_directed_change_done_reg/D]
