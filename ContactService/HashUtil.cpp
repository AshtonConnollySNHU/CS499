// HashUtil.cpp : Defines the functions for hashing using Windows CNG API.
#include "HashUtil.hpp"

#include <Windows.h>
#include <bcrypt.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stdexcept>

#pragma comment(lib, "bcrypt.lib")

using namespace std;

namespace HashUtil
{
	string bytesToHexLower(const unsigned char* bytes, size_t length) {
		ostringstream oss;
		for (size_t i = 0; i < length; ++i) {
			oss << hex << setw(2) << setfill('0') << (int)bytes[i];
		}
		return oss.str();
	}

	string sha256Hex(const string& input) {
		BCRYPT_ALG_HANDLE hAlg = nullptr;
		BCRYPT_HASH_HANDLE hHash = nullptr;

		DWORD cbData = 0;
		DWORD cbHashObject = 0;
		DWORD cbHash = 0;

		// SHA256 Provider
		if (BCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, nullptr, 0) != 0) {
			throw runtime_error("Failed to open algorithm provider.");
		}

		// Hash Object Size
		if (BCryptGetProperty(hAlg, BCRYPT_OBJECT_LENGTH, reinterpret_cast<PUCHAR>(&cbHashObject
			), sizeof(cbHashObject), &cbData, 0) != 0) {
			BCryptCloseAlgorithmProvider(hAlg, 0);
			throw runtime_error("Failed to get hash object size.");
		}

		if (BCryptGetProperty(hAlg, BCRYPT_HASH_LENGTH, reinterpret_cast<PUCHAR>(&cbHash), sizeof(cbHash), &cbData, 0) != 0) {
			BCryptCloseAlgorithmProvider(hAlg, 0);
			throw runtime_error("Failed to get hash size.");
		}

		vector<UCHAR> hashObject(cbHashObject);
		vector<UCHAR> hash(cbHash);

		// Create Hash
		if (BCryptCreateHash(hAlg, &hHash, hashObject.data(), cbHashObject, nullptr, 0, 0) != 0) {
			BCryptCloseAlgorithmProvider(hAlg, 0);
			throw runtime_error("Failed to create hash.");
		}

		// Hash Data
		if (BCryptHashData(hHash,reinterpret_cast<PUCHAR>(const_cast<char*>(input.data())), static_cast<ULONG>(input.size()), 0) != 0) {
			BCryptDestroyHash(hHash);
			BCryptCloseAlgorithmProvider(hAlg, 0);
			throw runtime_error("Failed to hash data.");
		}

		// Finish Hash
		if (BCryptFinishHash(hHash, hash.data(), cbHash, 0) != 0) {
			BCryptDestroyHash(hHash);
			BCryptCloseAlgorithmProvider(hAlg, 0);
			throw runtime_error("Failed to finish hash.");
		}

		// Clean up
		BCryptDestroyHash(hHash);
		BCryptCloseAlgorithmProvider(hAlg, 0);

		// Convert hash to hex string
		return bytesToHexLower(hash.data(), hash.size());
		}

	}