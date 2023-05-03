# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\work\Goldenbell2\GoldenBell2_22.2_pratice_20230428\zynq-7000\workspace\goldenbell2\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\work\Goldenbell2\GoldenBell2_22.2_pratice_20230428\zynq-7000\workspace\goldenbell2\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {goldenbell2}\
-hw {C:\work\Goldenbell2\GoldenBell2_22.2_pratice_20230428\zynq-7000\workspace\design_1_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {C:/work/Goldenbell2/GoldenBell2_22.2_pratice_20230428/zynq-7000/workspace}

platform write
platform generate -domains 
platform active {goldenbell2}
platform generate
platform clean
