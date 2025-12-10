# 🇻🇳 Hướng Dẫn Build Dự Án ESP32 OTTO

## 🚀 Giới Thiệu

Dự án **Xiaozhi ESP32 OTTO** là firmware dành cho thiết bị hiển thị và điều khiển bằng LVGL trên chip **ESP32-S3**, hỗ trợ:
- Giao diện đồ họa LVGL.
- Đa ngôn ngữ (tự động sinh từ JSON).
- Wi-Fi cấu hình và OTA update.
- Âm thanh `.ogg` tích hợp sẵn trong firmware.

---

## Build OTTO Robot Firmware (ESP32-S3)

Quick recipe using ESP-IDF 5.4+ on Windows PowerShell:

1. Export ESP-IDF env (adjust path to your install):
   ```powershell
   Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
   & "C:\Espressif\frameworks\esp-idf-v5.5.1\export.ps1"
   idf.py --version   # should show ESP-IDF v5.x
   ```
2. Build OTTO (optionally remove old zip so release.py rebuilds):
   ```powershell
   cd f:\xiaozhi-esp32-OTTO
   Remove-Item -Force .\releases\v2.0.3_otto-robot.zip -ErrorAction SilentlyContinue
   python scripts\release.py otto-robot --name otto-robot
   ```
   The merged binary is packaged to `releases\v2.0.3_otto-robot.zip` (contains `merged-binary.bin`).
3. Flash to board:
   ```powershell
   idf.py -p COM3 -b 921600 flash   # replace COM3 with your port
   ```
