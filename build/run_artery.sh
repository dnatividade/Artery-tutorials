#!/bin/bash
OPP_RUNALL=/home/veins/src/omnetpp/bin/opp_runall
OPP_RUN=/home/veins/src/omnetpp/bin/opp_run_dbg
NED_FOLDERS="/home/veins/artery/src/artery:/home/veins/artery/src/traci:/home/veins/artery/extern/veins/examples/veins:/home/veins/artery/extern/veins/src/veins:/home/veins/artery/extern/inet/src:/home/veins/artery/extern/inet/examples:/home/veins/artery/extern/inet/tutorials:/home/veins/artery/extern/inet/showcases"
LIBRARIES="-l/home/veins/artery/build/src/artery/libartery_core.so -l/home/veins/artery/build/src/traci/libtraci.so -l/home/veins/artery/build/extern/libveins.so -l/home/veins/artery/build/extern/libINET.so -l/home/veins/artery/build/src/artery/storyboard/libartery_storyboard.so -l/home/veins/artery/build/src/artery/envmod/libartery_envmod.so"

RUNALL=false
for arg do
    shift
    [[ "$arg" == -j* ]] && RUNALL=true && J=$arg && continue
    [[ "$arg" == -b* ]] && RUNALL=true && B=$arg && continue
    # run opp_runall with default values for -j* and -b* options by just specifying '--all'
    [[ "$arg" == "--all" ]] && RUNALL=true && continue
    set -- "$@" "$arg"
done

if [ "$RUNALL" = true ] ; then
    $OPP_RUNALL $J $B $OPP_RUN -n $NED_FOLDERS $LIBRARIES $@
else
    $OPP_RUN -n $NED_FOLDERS $LIBRARIES $@
fi
