var checkInclusion = function(s1, s2) 
{
    const createFrequencyMap = (str) => {
        const map = Array(26).fill(0);
        for (let char of str) 
        {
            map[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        
        return map;
    };
    
    if (s1.length > s2.length)
    {
        return false;
    }
    
    const s1Map = createFrequencyMap(s1);
    const s2Map = createFrequencyMap(s2.slice(0, s1.length));
    
    const matches = (map1, map2) => {
        for (let i = 0; i < 26; i++) 
        {
            if (map1[i] !== map2[i])
            {
                return false;
            }
        }

        return true;
    };
    
    if (matches(s1Map, s2Map))
    {
        return true;
    }
    
    for (let i = s1.length; i < s2.length; i++) 
    {
        s2Map[s2[i - s1.length].charCodeAt(0) - 'a'.charCodeAt(0)]--;
        s2Map[s2[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    
        if (matches(s1Map, s2Map))
        {
            return true;
        }
    }
    
    return false;
};