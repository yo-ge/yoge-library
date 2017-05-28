import numpy as np

def DFT_slow(x):
    """
    Compute the discrete Fourier Transform of the 1D array x.
    Straight forward yet slow version.
    """
    x = np.asarray(x, dtype=float)
    N = x.shape[0]
    n = np.arange(N)
    k = n.reshape((N, 1))
    M = np.exp(-2j * np.pi * k * n / N)
    return np.dot(M, x)


def FFT(x):
    """
    A recursive implementation of the 1D Cooley-Tukey FFT
    """
    x = np.asarray(x, dtype=float)
    N = x.shape[0]

    if N % 2 > 0:
        raise ValueError("size of x must be a power of 2")
    elif N <= 32:  # this cutoff should be optimized
        return DFT_slow(x)
    else:
        X_even = FFT(x[::2])
        X_odd = FFT(x[1::2])
        factor = np.exp(-2j * np.pi * np.arange(N) / N)
        return np.concatenate([X_even + factor[:N / 2] * X_odd,
                               X_even + factor[N / 2:] * X_odd])


if __name__ == '__main__':
    A = np.array([n**2 for n in range(2**50+1)])
    print((A))
    print(1)
    # B = np.arange(2**20)
    # A_star = np.fft.fft(A)
    # B_star = np.fft.fft(B)
    # C = np.dot(A_star, B_star)
    # print(np.fft.ifft(C.shape[0]))

