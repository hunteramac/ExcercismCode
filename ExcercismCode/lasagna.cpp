// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
int ovenTime() {
    return 40;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven.
*/
int remainingOvenTime(int actualMinutesInOven) {
    int curRemainingOventTime = ovenTime() - actualMinutesInOven;
    if (curRemainingOventTime < 0)
        return 0;
    else
        return curRemainingOventTime;
}

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer.
*/
int preparationTime(int numberOfLayers) {
    return 2*numberOfLayers;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}
