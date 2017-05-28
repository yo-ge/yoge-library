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


if __name__ == '__main__':
    A = np.arange(2**50)
    B = np.arange(2**20)
    A_star = np.fft.fft(A)
    B_star = np.fft.fft(B)
    C = np.dot(A_star, B_star)
    print(np.fft.ifft(C.shape[0]))

