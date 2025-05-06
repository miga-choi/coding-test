class LicenseKeyFormatting:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace("-", "").upper()
        result = ""

        for i in range(len(s) - 1, -1, -k):
            if i >= k:
                result = "-" + s[-k:] + result
            else:
                result = s[-k:] + result
            s = s[: i + 1 - k]

        return result


    # Solution
    def solution(self, s: str, k: int) -> str:
        s = s.replace("-", "").upper()[::-1]
        return "-".join(s[i : i + k] for i in range(0, len(s), k))[::-1]
