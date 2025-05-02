/**
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 */
var carFleet = function(target, position, speed) 
{
    let cars = position.map((pos, idx) => [pos, (target - pos) / speed[idx]]);
    
    cars.sort((a, b) => b[0] - a[0]);
    
    let fleets = 0;
    let currentTime = 0;
    
    for (let i = 0; i < cars.length; i++) 
    {
        let [pos, time] = cars[i];
        if (time > currentTime) 
        {
            fleets++;
            currentTime = time;
        }
    }
    
    return fleets;
};