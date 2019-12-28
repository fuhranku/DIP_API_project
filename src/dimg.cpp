#include "DIMG.h"


DIMG::DIMG(){
	// Initialize matrix
	/*memset(mat, 0x0001, sizeof mat);*/
	mat = vector<int>(49, 1);
	// Default 3x3 Kernel's size
	size = glm::ivec2(3);
}


DIMG::~DIMG(){
}

void DIMG::reloadShader() {
	delete shader;
	switch (currentShader) {
	case DIMG_COLOR:
		shader = new Shader("assets/shaders/basic.vert", "assets/shaders/basic.frag");
		break;
	case DIMG_NEGATIVE:
		shader = new Shader("assets/shaders/negative.vert", "assets/shaders/negative.frag");
		break;
	case DIMG_GRAYSCALE:
		shader = new Shader("assets/shaders/grayscale.vert", "assets/shaders/grayscale.frag");
		break;
	case DIMG_BLACKANDWHITE:
		shader = new Shader("assets/shaders/blackandwhite.vert", "assets/shaders/blackandwhite.frag");
		break;
	case DIMG_SOBEL_GRAD:
		shader = new Shader("assets/shaders/sobel.vert", "assets/shaders/sobel.frag");
		break;
	case DIMG_ROBERTS_GRAD:
		shader = new Shader("assets/shaders/roberts.vert", "assets/shaders/roberts.frag");
		break;
	case DIMG_PREWITT_GRAD:
		shader = new Shader("assets/shaders/prewitt.vert", "assets/shaders/prewitt.frag");
		break;
	case DIMG_MEAN_BLUR:
		shader = new Shader("assets/shaders/mean.vert", "assets/shaders/mean.frag");
		break;
	case DIMG_MEDIAN_BLUR:
		shader = new Shader("assets/shaders/median.vert", "assets/shaders/median.frag");
		break;
	case DIMG_GAUSSIAN_BLUR:
		shader = new Shader("assets/shaders/gaussian.vert", "assets/shaders/gaussian.frag");
		break;
	}
}

void DIMG::setKernelSize(int h, int w) {
	size = glm::ivec2(h, w);
}

void DIMG::color(GLuint image) {
	shader = new Shader("assets/shaders/basic.vert", "assets/shaders/basic.frag");
	currentShader = DIMG_COLOR;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
}

void DIMG::negative(GLuint image){
	shader = new Shader("assets/shaders/negative.vert", "assets/shaders/negative.frag");
	currentShader = DIMG_NEGATIVE;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
}

void DIMG::grayscale(GLuint image) {
	shader = new Shader("assets/shaders/grayscale.vert", "assets/shaders/grayscale.frag");
	currentShader = DIMG_GRAYSCALE;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
}

void DIMG::blackandwhite(GLuint image) {
	shader = new Shader("assets/shaders/blackandwhite.vert", "assets/shaders/blackandwhite.frag");
	currentShader = DIMG_BLACKANDWHITE;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
}

void DIMG::sobel(GLuint image){
	setMatText();
	shader = new Shader("assets/shaders/sobel.vert", "assets/shaders/sobel.frag");
	currentShader = DIMG_SOBEL_GRAD;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	shader->setInt("matrix", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, matTex);
}

void DIMG::roberts(GLuint image) {
	setMatText();
	shader = new Shader("assets/shaders/roberts.vert", "assets/shaders/roberts.frag");
	currentShader = DIMG_ROBERTS_GRAD;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	shader->setInt("matrix", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, matTex);
}

void DIMG::prewitt(GLuint image) {
	setMatText();
	shader = new Shader("assets/shaders/prewitt.vert", "assets/shaders/prewitt.frag");
	currentShader = DIMG_PREWITT_GRAD;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	shader->setInt("matrix", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, matTex);
}

void DIMG::mean(GLuint image) {
	setMatText();
	shader = new Shader("assets/shaders/mean.vert", "assets/shaders/mean.frag");
	currentShader = DIMG_MEAN_BLUR;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	shader->setInt("matrix", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, matTex);
}

void DIMG::median(GLuint image) {
	setMatText();
	shader = new Shader("assets/shaders/median.vert", "assets/shaders/median.frag");
	currentShader = DIMG_MEDIAN_BLUR;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	shader->setInt("matrix", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, matTex);
}

void DIMG::gaussianLaplace(GLuint image) {
	setMatText();
	shader = new Shader("assets/shaders/gaussianLaplace.vert", "assets/shaders/gaussianLaplace.frag");
	currentShader = DIMG_GAUSSIAN_BLUR;
	shader->use();
	// Send image to GPU
	shader->setInt("image", 0);
	shader->setInt("matrix", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, matTex);
}

void DIMG::setMatText(){
	glGenTextures(1, &matTex);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, matTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32I, 7, 7, 0, GL_RED_INTEGER, GL_INT, mat.data());
}

std::string DIMG::loadPath(){
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "JPG Files(.jpg)\0*.jpg\0PNG Files(.png)\0*.png\0JPEG Files(.jpeg)\0*.jpeg;";
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "";
	ofn.lpstrTitle = "Select an image";
	std::string fileNameStr;
	if (GetOpenFileName(&ofn)) {
		fileNameStr = fileName;
	}
	std::cout << fileNameStr << std::endl;
	return fileNameStr;
}

std::string DIMG::savePath(){
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "JPG Files(.jpg)\0*.jpg\0PNG Files(.png)\0*.png\0JPEG Files(.jpeg)\0*.jpeg;";
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "";
	ofn.lpstrTitle = "Save image as...";
	std::string fileNameStr;
	if (GetSaveFileNameA(&ofn)) {
		fileNameStr = fileName;
	}
	std::cout << fileNameStr << std::endl;
	return fileNameStr;
}

//void DIMG::saveImage(GLuint image) {
//	GLubyte* pixels = new GLubyte[800 * 600 * 3];
//	glBindTexture(GL_TEXTURE_2D, image);
//	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
//	// You have to use 3 comp for complete jpg file. If not, the image will be grayscale or nothing.
//	stbi_flip_vertically_on_write(true); // flag is non-zero to flip data vertically
//	stbi_write_jpg(savePath().c_str(), 800, 600, 3, pixels, 100);
//}
