# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\work\Goldenbell2\GoldenBell2_22.2_NVMe_multicore_20230503\workspace\nvme\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\work\Goldenbell2\GoldenBell2_22.2_NVMe_multicore_20230503\workspace\nvme\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {nvme}\
-hw {C:\work\Goldenbell2\GoldenBell2_22.2_NVMe_multicore_20230503\workspace\design_1_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {C:/work/Goldenbell2/GoldenBell2_22.2_NVMe_multicore_20230503/workspace}

platform write
platform generate -domains 
domain create -name {ps7_cortexa9_1} -os {standalone} -proc {ps7_cortexa9_1} -arch {32-bit} -display-name {ps7_cortexa9_1} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
domain active {zynq_fsbl}
bsp reload
bsp config stdin "ps7_uart_1"
bsp config stdout "ps7_uart_1"
bsp write
bsp reload
catch {bsp regenerate}
domain active {standalone_domain}
bsp reload
bsp config stdin "ps7_uart_1"
bsp config stdout "ps7_uart_1"
bsp write
bsp reload
catch {bsp regenerate}
domain active {ps7_cortexa9_1}
bsp reload
bsp config stdin "ps7_uart_1"
bsp config stdout "ps7_uart_1"
bsp write
bsp reload
catch {bsp regenerate}
platform generate
platform clean
