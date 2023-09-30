/*
 * Artery V2X Simulation Framework
 * Copyright 2019 Raphael Riebl
 * Licensed under GPLv2, see COPYING file for detailed license and warranty terms.
 */

#include "artery/utility/Identity.h"
#include <omnetpp/regmacros.h>
#include <limits>

namespace artery
{

// Identity has no source file yet
Register_Class(Identity)

using namespace omnetpp;

const simsignal_t Identity::changeSignal = cComponent::registerSignal("IdentityChanged");

bool Identity::update(const Identity& update, long changes)
{
    bool changed = false;

    if (changes & ChangeTraCI) {
        traci = update.traci;
        changed = true;
    }

    if (changes & ChangeStationId) {
        application = update.application;
        changed = true;
    }

    if (changes & ChangeGeoNetAddress) {
        geonet.insert(update.geonet.begin(), update.geonet.end());
        changed = true;
    }

    return changed;
}

uint32_t Identity::randomStationId(omnetpp::cRNG* rng)
{
    return intuniform(rng, 0, std::numeric_limits<uint32_t>::max());
}

uint32_t Identity::deriveStationId(omnetpp::cModule* mod, const std::string& basis)
{
    if (basis == "random") {
        return randomStationId(mod->getRNG(0));
    } else if (basis == "component") {
        return mod->getId();
    } else if (basis == "module-index") {
        return mod->isVector() ? mod->getIndex() : -1;
    } else {
        throw omnetpp::cRuntimeError("unknown basis %s to derive station id from", basis.c_str());
        return 0;
    }
}

} // namespace artery
