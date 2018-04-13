# Maintainer: David "JohnBobSmith" Bogner <myrunescapeemail609 AT gmail DOT com>
pkgname=attackoftheasteroids-git
_pkgname=attackoftheasteroids
pkgver=r30.94e29a2
pkgrel=1
pkgdesc="A simple 2D shooting and defense game."
arch=(x86_64)
depends=('sfml')
makedepends=('git')
url="https://github.com/JohnBobSmith/attackoftheasteroids"
license=('MIT')
source=("git+https://github.com/JohnBobSmith/attackoftheasteroids.git")
md5sums=('SKIP')

pkgver() {
  cd "$_pkgname"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd "$_pkgname"
	make
}

package() {
	cd "$_pkgname"
	make DESTDIR="$pkgdir/" install
}


