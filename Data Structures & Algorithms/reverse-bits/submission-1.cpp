class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; i++) {

            // Step 1: shift the i-th bit to the rightmost position
            uint32_t shifted = n >> i;

            // Step 2: extract that bit (0 or 1)
            uint32_t bit = shifted & 1;

            // Step 3: compute where this bit should go in the result
            int targetPos = 31 - i;

            // Step 4: move the bit to its reversed position
            uint32_t placedBit = bit << targetPos;

            // Step 5: add it to the result
            res = res + placedBit;
        }

        return res;
    }
};
