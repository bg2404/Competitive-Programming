namespace Qrng {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation QuantumRandomNumberGenerator() : Result {
        using (q = Qubit())  {  // Allocate a qubit.
            H(q);               // Put the qubit to superposition. It now has a 50% chance of being 0 or 1.
            return MResetZ(q);  // Measure the qubit value.
        }
    }

    operation RandomNumberInRange(max : Int) : Int {
        mutable bits = new Result[0];
        for (idxBit in 1..BitSizeI(max)) {
            set bits += [QuantumRandomNumberGenerator()];
        }
        let sample = ResultArrayAsInt(bits);
        return sample > max
            ? RandomNumberInRange(max)
            | sample;
    }
    
    @EntryPoint()
    operation RandomNumber() : Int {
        let max = 50;
        Message($"Sampling a random number between 0 and {max}: ");
        return RandomNumberInRange(max);
    }
}