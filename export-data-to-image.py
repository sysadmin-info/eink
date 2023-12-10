import subprocess
from PIL import Image, ImageDraw, ImageFont
# Function to get disk usage data
def get_disk_usage():
# df -h wyświetla wszystkie dyski w tzw. human readable format. Możesz dać df -h /home
process = subprocess.Popen(['df', '-h'], stdout=subprocess.PIPE)
out, err = process.communicate()
# Function to create an image with text
def create_image_with_text(text, image_file):
# Create an image with white background
image = Image.new('RGB', (400, 200), color='white')
draw = ImageDraw.Draw(image)
# Load a font
font = ImageFont.load_default()
# Add text
draw.text((10, 10), text, fill='black', font=font)
# Save the image
image.save(image_file)
# Main process
disk_usage = get_disk_usage()
create_image_with_text(disk_usage, 'disk_usage.png')
