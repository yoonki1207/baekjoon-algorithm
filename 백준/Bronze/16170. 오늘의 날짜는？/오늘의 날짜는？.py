from datetime import datetime, timezone

now = datetime.now(timezone.utc)  # 현재 시각 (UTC+0)
print(f"{now.year:04d}")
print(f"{now.month:02d}")
print(f"{now.day:02d}")